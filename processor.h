#pragma once

#include <memory>

typedef struct node_t
{
    double m_value;
    node_t(double value = 0) : m_value(value) { }
} node_t;

typedef std::shared_ptr<node_t> node_ptr_t;

inline node_ptr_t op_add(node_ptr_t x, node_ptr_t y)
{
    return std::make_shared<node_t>(x->m_value + y->m_value);
}
inline node_ptr_t op_sub(node_ptr_t x, node_ptr_t y)
{
    return std::make_shared<node_t>(x->m_value - y->m_value);
}
inline node_ptr_t op_mul(node_ptr_t x, node_ptr_t y)
{
    return std::make_shared<node_t>(x->m_value * y->m_value);
}
inline node_ptr_t op_uminus(node_ptr_t x)
{
    return std::make_shared<node_t>(-x->m_value);
}

typedef double parse_result_t;

int yylex(void);
void yyerror(parse_result_t *result, const char *s);
