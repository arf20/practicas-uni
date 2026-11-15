#ifndef _SBR_H
#define _SBR_H

#include <stddef.h>
#include <stdint.h>

#define OPER_AND    0   /* conjunction */
#define OPER_OR     1   /* disjunction */

typedef struct {
    size_t          r_id;           /* rule id: R1 */
    int             r_oper;         /* 0 = conjunction, 1 = disjunction */
    uint8_t         r_inputs[32];   /* literals: h0, h1... */
    unsigned int    r_inputs_size;  /* size of literal vector */
    char            r_output;       /* output literal */
    float           r_cert;         /* rule certainty factor */
} rule_t;

typedef struct {
    int             f_oper;         /* 0 = conjunction, 1 = disjunction */
    uint8_t         f_lits[32];     /* literals: h0, h1... */
    unsigned int    f_lits_size;    /* size of literal vector */
    float           f_cert;         /* fact certainty factor */
} fact_t;

#endif /* _SBR_H */
