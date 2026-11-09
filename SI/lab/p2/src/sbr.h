#ifndef _SBR_H
#define _SBR_H

typedef struct {
    int             r_id;       /* rule id: R1 */
    int             r_type;     /* 0 = conjunction, 1 = disjunction */
    char            r_lits[32]; /* literals: h0, h1... */
    unsigned int    r_size;     /* size of literal vector */
    float           r_cert;     /* rule certainty factor */
} rule_t;

typedef struct {
    int             f_lit_id;   /* literal id (r_lits) */
    float           f_cert;     /* fact certainty factor */
} fact_t;

#endif /* _SBR_H */
