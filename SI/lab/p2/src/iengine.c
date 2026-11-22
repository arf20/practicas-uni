#include "iengine.h"
#include "base.h"

#include <stdlib.h>

/*

FOR REFERENCE

generic_inference_engine() {
    while (!completion_condition(fb) && !stop_action) {
        conflict_set = equate(rb, fb);
        r = solve(conflict_set);
        new_facts = apply(r, fb);
        update(fb, new_facts);
    }
}

forward_linking(rb, ifb) {
    fb = ifb; cs = {}; applied_rules = {};
    do {
        cs -= applied_rules
        cs += equate(antecedents(rb, fb))
        if (!empty(cs)) {
            r = solve(cs);
            new_facts = apply(r, fb);
            applied_rules applied_rules + {r}
            update(fb, new_facts);
        }
    } while (contains(goal, fb) || empty(cs));
    return contains(goal, fb);
}

THIS CASE

backwards_linking(rb, ifb) {
    fb = ifb;
    return verify(rb, fb);
}

verify(rb, ifb) {
    if (contains(goal, fb))
        return true;
    cs = equate(consequentials(rb), goal);  // this means picking rules that have goal as output
    verified = false;
    while (!empty(cs) && !verified) {
        r = solve(cs);                      // this means selecting a rule somehow
        remove(r, cc);
        new_goals = antecedents(r);
        verified = true;
        while (!empty(new_goals) && verified) {
            new_goal = select_goal(new_goal);
            remove(new_goal, new_goals);
            verified = verify(new_goal, fb);
        }
        if (verified)
            insert(goal, fb);
        return verified;
    }
}
*/

int factbase_contains(const factbase_t *fb, uint8_t l)
{
    for (size_t i = 0; i < fb->fb_facts_size; i++)
        if (fb->fb_facts[i].f_lits_size == 1 && fb->fb_facts[i].f_lits[0] == l)
            return 1;
    return 0;
}

/* filter rules by having goal as output (consequent) */
void rulebase_filter(const rulebase_t *rb, uint8_t goal, rulebase_t *cs)
{
    for (size_t i = 0; i < rb->rb_rules_size; i++)
        if (rb->rb_rules[i].r_output == goal)
            rulebase_insert(cs, &rb->rb_rules[i]);
}

const rule_t *solve(const rulebase_t *rb)
{
    if (rb->rb_rules && rb->rb_rules_size)
        return &rb->rb_rules[0];
    else return NULL;
}

int verify(const rulebase_t *rb, factbase_t *fb, uint8_t goal)
{
    if (factbase_contains(fb, goal))
        return 1;

    rulebase_t cs = { 0 };
    rulebase_filter(rb, goal, &cs);
    int verified = 0;

    while (cs.rb_rules_size > 0 && !verified) {
        const rule_t *r = solve(&cs);
        rule_t sel_rule = *r;
        rulebase_remove(&cs, r);

        verified = 1;
        while (sel_rule.r_inputs_size > 0 && verified) {
            uint8_t newgoal = sel_rule.r_inputs[sel_rule.r_inputs_size - 1];
            sel_rule.r_inputs_size--;
            verified = verify(rb, fb, newgoal);
        }

        if (verified)
            factbase_insert(fb, goal);
    }
    
    return verified;
}

int backwards_chaining(const rulebase_t *rb, const factbase_t *ifb, factbase_t *fb)
{
    factbase_clone(fb, ifb);
    return verify(rb, fb, fb->fb_goal);
}

