#!/usr/bin/python3

from calculator_1 import add, sub, mul, div

a = 10
b = 5

sum_of = add(a, b)
diff_of = sub(a, b)
product_of = mul(a, b)
quotient_of = div(a, b)

print(f"{a} + {b} = {sum_of}")
print(f"{a} - {b} = {diff_of}")
print(f"{a} * {b} = {product_of}")
print(f"{a} / {b} = {quotient_of}")
