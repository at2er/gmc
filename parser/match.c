#include "keywords.h"
#include "token.h"
#include "block.h"

static int match_block_parse(struct file *f, struct token *fn);
static int match_condition_parse(struct file *f);
static int match_conditions_parse(struct file *f);

int match_block_parse(struct file *f, struct token *fn)
{
    while (f->src[f->pos] != '\n') {
        parse_block(f, fn);
    }

    return 0;
}

int match_condition_parse(struct file *f)
{
    return 0;
}

int match_conditions_parse(struct file *f)
{
    while (f->src[f->pos] != '\n') {
        match_condition_parse(f);
    }

    return 0;
}

int parse_match(struct file *f, struct token *t, struct token *fn)
{
    file_try_skip_space(f);

    match_conditions_parse(f);

    return 0;
}
