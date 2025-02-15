#pragma once

#include "operators/unary.h"

namespace infini {
// TODO(constroy): num should be size_t.
void softmax_kernel(float *input, float *output, int num);
void relu_kernel(float *input, float *output, int num);
void sigmoid_kernel(float *input, float *output, int num);
void tanh_kernel(float *input, float *output, int num);
void abs_kernel(float *input, float *output, int num);
void sqrt_kernel(float *input, float *output, int num);
void erf_kernel(float *input, float *output, int num);

void unary_kernel(const Operator &_op) {
    auto op = as<UnaryObj>(_op);
    float *const inputData = (op->getInputs(0)->getRawDataPtr<float *>());
    float *const outputData = (op->getOutput()->getRawDataPtr<float *>());

    size_t num = op->getOutput()->size();
    if (op->getOpType() == OpType::Softmax)
        softmax_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Relu)
        relu_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Sigmoid)
        sigmoid_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Tanh)
        tanh_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Abs)
        abs_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Sqrt)
        sqrt_kernel(inputData, outputData, num);
    else if (op->getOpType() == OpType::Erf)
        erf_kernel(inputData, outputData, num);
    else
        IT_TODO_HALT();
}

}; // namespace infini
