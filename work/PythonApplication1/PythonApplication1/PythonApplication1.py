import cmath
import math
while True:
            a,b,c = eval(input())
            delta=b * b - 4 * a * c
            if delta==0:
                 print("有两个相等的实根x1=x2={:.1f}".format(-b/(2*a)))
            elif delta>0:
                 sqrtdelta = math.sqrt(delta)
                 x1 = (-b + sqrtdelta) / (2 * a)
                 x2 = (-b - sqrtdelta) / (2 * a)
                 print("有两个不相等的实根")
                 print("x1={:.2f}".format(x1))
                 print("x2={:.2f}".format(x2))
            else:
                 sqrtdelta = cmath.sqrt(delta)
                 x1 = (-b + sqrtdelta) / (2 * a)
                 x2 = (-b - sqrtdelta) / (2 * a)
                 print("无实根，两个虚根")
                 print("C1={0.real:.3f}{0.imag:+.3f}j".format(x1) )
                 print("C2={0.real:.3f}{0.imag:+.3f}j".format(x2) )
            d=input()
            if d=='yes': continue
            if d=='no' : break
    