#include <stdlib.h>
#include <string.h>

#include "matching_brackets.h"

struct stack_item* stack_push (struct stack_item*, int);
char               stack_pop (struct stack_item**);
bool               is_pairing (const char, const char);

struct stack_item {
    char               item;
    struct stack_item* next;
};

struct stack_item*
stack_push (struct stack_item* head, int c)
{
    struct stack_item* new_head = malloc (sizeof (*new_head));
    new_head->item = c;
    new_head->next = head;
    return new_head;
}

char
stack_pop (struct stack_item** headp)
{
    if (headp == NULL || *headp == NULL)
        return '\0';

    struct stack_item* old_head = (*headp);
    const char         c = old_head->item;
    (*headp) = old_head->next;
    free (old_head);

    return c;
}

#define OPEN_BRACKETS "{[("
#define CLOS_BRACKETS "}])"

bool
is_pairing (const char open, const char close)
{
    static const char* open_brackets = OPEN_BRACKETS;
    static const char* close_brackets = CLOS_BRACKETS;
    static const int   len = sizeof (OPEN_BRACKETS);

    int i = 0;
    while (open != open_brackets[i] && i < len)
        i++;
    return i < len && close == close_brackets[i];
}

bool
is_paired (const char* input)
{
    struct stack_item* stack_head = NULL;

    while (*input) {
        if (strchr (OPEN_BRACKETS, *input) != NULL) {
            // if in the set of opening brackets
            stack_head = stack_push (stack_head, *input);
        } else if (strchr (CLOS_BRACKETS, *input) != NULL) {
            // if in the set of closing brackets
            int c = stack_pop (&stack_head);
            if (!is_pairing (c, *input))
                return false;
        }
        input++;
    }

    // all brackets are paired if stack is emptied at the end
    return stack_head == NULL;
}
