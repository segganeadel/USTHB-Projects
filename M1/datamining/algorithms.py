import pandas as pd
import numpy as np
from itertools import combinations
from itertools import combinations

def support(df ,frequent_itemsets : list):
    return np.array([df.iloc[:,x].prod(1).mean() for x in frequent_itemsets])

def generate_candidates1(df):
    return np.arange(df.shape[1]).reshape(-1,1)

def generate_candidates2(frequent_itemsets):
    frequent_itemsets = [x[0] for x in frequent_itemsets]
    return np.array([list(x) for x in combinations(frequent_itemsets,2)])
   
def generate_candidatesK(df ,frequent_itemsets , k):
    candidates = []
    for i in range(len(frequent_itemsets)):
        for j in range(i+1,len(frequent_itemsets)):
            if np.array_equal(frequent_itemsets[i][:k-2], frequent_itemsets[j][:k-2]):
                candidates.append(list(set(frequent_itemsets[i]) | set(frequent_itemsets[j])))
    return np.array(candidates)

def apriori (df, min_support, use_colnames=False):

    itemset_dict = {}
    support_dict = {}

    #generate set of 1-itemsets
    frequent1 = generate_candidates1(df)
    supparr = support(df,frequent1)
    itemset_dict[1] = frequent1[supparr >= min_support]
    support_dict[1] = supparr[supparr >= min_support].reshape(-1,1)
    if itemset_dict[1].shape[0] == 0:
        del itemset_dict[1]
        del support_dict[1]
        return itemset_dict,support_dict
 

    #generate set of 2-itemsets
    frequent2 = generate_candidates2(itemset_dict[1])
    supparr = support(df,frequent2)
    itemset_dict[2] = frequent2[supparr >= min_support]
    support_dict[2] = supparr[supparr >= min_support].reshape(-1,1)
    if itemset_dict[2].shape[0] == 0:
        del itemset_dict[2]
        del support_dict[2]
        return itemset_dict,support_dict


    #generate set of k-itemsets
    frequen_prev = frequent2 
    k = 3
    while True:
        frequentk = generate_candidatesK(df,frequen_prev,k)
        supparr = support(df,frequentk)
        itemset_dict[k] = frequentk[supparr >= min_support]
        support_dict[k] = supparr[supparr >= min_support].reshape(-1,1)
        frequen_prev = itemset_dict[k]   
        if itemset_dict[k].shape[0] == 0:
            del itemset_dict[k]
            del support_dict[k]
            return itemset_dict,support_dict
        k += 1


def aprioriclose(df, min_support,use_colnames=False):
    itemset_dict,support_dict = apriori(df, min_support)
    closed_itemset_dict = {}
    closed_support_dict = {}
    for k in itemset_dict.keys():
        closed_itemset_dict[k] = []
        closed_support_dict[k] = []
        for i in range(itemset_dict[k].shape[0]):
            isclosed = True
            for j in range(itemset_dict[k].shape[0]):
                if i != j and set(itemset_dict[k][i]).issubset(set(itemset_dict[k][j])) and support_dict[k][i] == support_dict[k][j]:
                    isclosed = False
                    break
            if isclosed:
                closed_itemset_dict[k].append(itemset_dict[k][i])
                closed_support_dict[k].append(support_dict[k][i])
        closed_itemset_dict[k] = np.array(closed_itemset_dict[k])
        closed_support_dict[k] = np.array(closed_support_dict[k])
    return closed_itemset_dict,closed_support_dict

def dict_to_df(df, itemset_dict, support_dict, use_colnames=False): 
    all_res = []
    for k in sorted(itemset_dict):
        support = pd.Series(support_dict[k].flatten())
        itemsets = pd.Series([frozenset(i) for i in itemset_dict[k]], dtype="object")

        res = pd.concat((support, itemsets), axis=1)
        all_res.append(res)

    res_df = pd.concat(all_res)
    res_df.columns = ["support", "itemsets"]
    if use_colnames:
        mapping = {idx: item for idx, item in enumerate(df.columns)}
        res_df["itemsets"] = res_df["itemsets"].apply(
            lambda x: frozenset([mapping[i] for i in x])
        )
    res_df = res_df.reset_index(drop=True)

    return res_df