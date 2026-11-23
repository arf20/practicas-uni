#ifndef _BASE_H
#define _BASE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define OPER_AND    0   /* conjunction */
#define OPER_OR     1   /* disjunction */

typedef struct {
    char           *l_name;
    int32_t         l_id;
} lit_t;

typedef struct {
    size_t          lb_lits_size;
    lit_t          *lb_lits;
} litbase_t;

typedef struct {
    size_t          r_id;           /* rule id: R1 */
    int             r_oper;         /* 0 = conjunction, 1 = disjunction */
    int32_t         r_inputs[32];   /* literals: h0, h1... */
    unsigned int    r_inputs_size;  /* size of literal vector */
    char            r_output;       /* output literal */
    float           r_cert;         /* rule certainty factor */
} rule_t;

typedef struct {
    int             f_oper;         /* 0 = conjunction, 1 = disjunction */
    int32_t         f_lits[32];     /* literals: h0, h1... */
    unsigned int    f_lits_size;    /* size of literal vector */
    float           f_cert;         /* fact certainty factor */
} fact_t;

typedef struct {
    size_t          rb_rules_size;
    rule_t         *rb_rules;
} rulebase_t;

typedef struct {
    size_t          fb_facts_size;
    fact_t         *fb_facts;
    int32_t         fb_goal;        /* literal */
} factbase_t;


void litbase_init(litbase_t *lb);
int32_t litbase_lit(litbase_t *lb, const char *lname);
const char *litbase_lookup_name(const litbase_t *lb, int32_t lid);
int32_t litbase_lookup_id(const litbase_t *lb, const char *lname);
void litbase_print(const litbase_t *lb);

/* init empty null rulebase */
void rulebase_init(rulebase_t *rb);
void rulebase_insert(rulebase_t *rb, const rule_t *r);
void rulebase_remove(rulebase_t *rb, const rule_t *r); /* r is ptr to rb.rb_rules */
/* read into null rulebase */
ssize_t rulebase_read(rulebase_t *rb, litbase_t *lb, FILE *f);
void rulebase_print(const rulebase_t *rb, const litbase_t *lb);

void factbase_insert(factbase_t *fb, int32_t l);
int factbase_read(factbase_t *fb, litbase_t *lb, FILE *f);
void factbase_print(const factbase_t *fb, const litbase_t *lb);
void factbase_clone(factbase_t *ofb, const factbase_t *ifb);

#endif /* _BASE_H */

