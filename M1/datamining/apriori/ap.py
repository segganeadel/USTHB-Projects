def apriori(transaction, nbMinOccurencies):
    # init L1
    last_set = []
    for elem in transaction:
        for elemb in elem:
            to_add = {elemb}
            if to_add not in last_set and countFrequency(transaction, to_add) >= nbMinOccurencies:
                last_set.append(to_add)
    all_sets = []
    k = 2

    while (len(last_set)) != 0:
        all_sets.append(last_set)
        next_set = []

        for sub_set_one in last_set:
            for sub_set_two in last_set:
                new_sub_set = sub_set_one | sub_set_two
                if len(new_sub_set) == k and countFrequency(transaction,
                                                            new_sub_set) >= nbMinOccurencies and new_sub_set not in next_set:
                    next_set.append(new_sub_set)
        last_set = next_set
        k += 1
    return all_sets


def countFrequency(transaction, last):
    # applies to each element of Transaction
    return sum(map(lambda elem: last.issubset(elem), transaction))


def printSets(s):
    for i in range(len(s)):
        print("  L", i + 1, " = ", s[i])


print("TEST 1: n=3")
T = [{1, 2, 5}, {1, 3, 5}, {1, 2}, {1, 2, 3, 4, 5}, {1, 2, 4, 5}, {2, 3, 5}, {1, 5}]
res = apriori(T, 3)
printSets(res)