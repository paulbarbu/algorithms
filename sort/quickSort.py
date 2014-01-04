def qs(v):
    if len(v) == 0:
        return list()

    pivot = v[len(v)//2]
    v.remove(pivot)

    smaller = qs([x for x in v if x <= pivot])
    greater = qs([x for x in v if x > pivot])

    smaller.append(pivot)
    smaller.extend(greater)

    return smaller


if '__main__' == __name__:
    print(qs([1, 3, 5, 3, 2, 7]))
