import re

import normalize


def comparar(A1, M1, D1, h1, m1, A2, M2, D2, h2, m2):
    if A1 > A2:
        return 1
    elif A1 < A2:
        return -1
    elif A1 == A2:
        if M1 > M2:
            return 1
        elif M1 < M2:
            return -1
        elif M1 == M2:
            if D1 > D2:
                return 1
            elif D1 < D2:
                return -1
            elif D1 == D2:
                if h1 > h2:
                    return 1
                elif h1 < h2:
                    return -1
                elif h1 == h2:
                    if m1 > m2:
                        return 1
                    elif m1 < m2:
                        return -1
                    elif m1 == m2:
                        return 0


def stime(fname, normdateprog, t1, t2):
    t1grps = re.search(normdateprog, t1).groups()
    t2grps = re.search(normdateprog, t2).groups()

    file = open(fname, "r")
    for line in file:
        if line == "\n":
            continue
        
        normline = normalize.normalize_date(line)

        m = re.search(normdateprog, normline)

        if (m != None):
            grps = m.groups()

            if ((comparar(grps[0], grps[1], grps[2], grps[3], grps[4],
                         t1grps[0], t1grps[1], t1grps[2], t1grps[3], t1grps[4]) == 1) and
                (comparar(grps[0], grps[1], grps[2], grps[3], grps[4],
                         t2grps[0], t2grps[1], t2grps[2], t2grps[3], t2grps[4]) == -1)):
                print(line, end='')
    file.close()

