import numpy as np #type: ignore
from numpy import linalg #type: ignore
from scipy.sparse import csr_matrix #type: ignore
import time



#-------------------Question 1-------------------#
N = 10
m_adja1 = np.array([
                            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                            [1, 0, 0, 1, 0, 0, 0, 0, 0, 0],
                            [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                            [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
                            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0],
                            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                            [0, 0, 0, 1, 0, 1, 0, 0, 1, 0],
                            [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
                            [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
                            ], dtype=float)

m_adja2 = np.array([
                            [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                            [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
                            [0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                            [0, 0, 0, 0, 1, 0, 0, 1, 0, 0],
                            [0, 0, 1, 0, 0, 1, 0, 0, 0, 0],
                            [0, 1, 0, 0, 0, 0, 1, 0, 0, 0],
                            [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                            [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
                            [0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
                            ], dtype=float)

m_adja3 = np.zeros((10, 10))
m_adja3[1, 0] = 1
m_adja3[2, 1] = 1
m_adja3[3, 1] = 1
m_adja3[3, 2] = 1
m_adja3[4, 5] = 1
m_adja3[5, 4] = 1
m_adja3[6, 8] = 1
m_adja3[7, 6] = 1
m_adja3[7, 8] = 1
m_adja3[8, 7] = 1
m_adja3[9, 2] = 1


#-------------------Question 2-------------------#
print("-------------------Question 2-------------------")

#calcul des matrices Q
Nj1 = np.sum(m_adja1, axis=0)
Nj2 = np.sum(m_adja2, axis=0)
Nj3 = np.sum(m_adja3, axis=0)

col_nj_pos1 = Nj1 > 0
Q1 = np.copy(m_adja1)
Q1[:, col_nj_pos1] = m_adja1[:, col_nj_pos1] / Nj1[col_nj_pos1]

col_nj_pos2 = Nj2 > 0
Q2 = np.copy(m_adja2)
Q2[:, col_nj_pos2] = m_adja2[:, col_nj_pos2] / Nj2[col_nj_pos2]

col_nj_pos3 = Nj3 > 0
Q3 = np.copy(m_adja3)
Q3[:, col_nj_pos3] = m_adja3[:, col_nj_pos3] / Nj3[col_nj_pos3]

#recherche des lignes vides
col_nulls1 = np.all(Q1 == 0, axis=0)
non_null_cols1 = Q1[:, ~col_nulls1]
print("Somme des colonnes non nulles de Q de l'exemple 1 :", np.sum(non_null_cols1, axis=0))

col_nulls2 = np.all(Q2 == 0, axis=0)
non_null_cols2 = Q2[:, ~col_nulls2]
print("Somme des colonnes non nulles de Q de l'exemple 2 :", np.sum(non_null_cols2, axis=0))

col_nulls3 = np.all(Q3 == 0, axis=0)
non_null_cols3 = Q3[:, ~col_nulls3]
print("Somme des colonnes non nulles de Q de l'exemple 3 :", np.sum(non_null_cols3, axis=0))


#-------------------Question 3-------------------#
print(" ")
print("-------------------Question 3-------------------")

vp1, _ = np.linalg.eig(Q1)
vp2, _ = np.linalg.eig(Q2)
vp3, _ = np.linalg.eig(Q3)
print("1 appartient-il aux valeurs propres de Q de l'exemple 1 ?", True in np.isclose(vp1, 1))
print("1 appartient-il aux valeurs propres de Q de l'exemple 2 ?", True in np.isclose(vp2, 1))
print("1 appartient-il aux valeurs propres de Q de l'exemple 3 ?", True in np.isclose(vp3, 1))

print("")

print("Multiplicité de 1 en valeur propre de Q pour l'exemple 1 :", np.isclose(1, vp1).sum())
print("Multiplicité de 1 en valeur propre de Q pour l'exemple 2 :", np.isclose(1, vp2).sum())
print("Multiplicité de 1 en valeur propre de Q pour l'exemple 3 :", np.isclose(1, vp3).sum())

#-------------------Question 4-------------------#
print(" ")
print("-------------------Question 4-------------------")

#calcul des matrices P
P1 = np.copy(Q1)
P1[:, Nj1 == 0] += 1./N

P2 = np.copy(Q2)
P2[:, Nj2 == 0] += 1./N

P3 = np.copy(Q3)
P3[:, Nj3 == 0] += 1./N

#calcul des vp
vp1, _ = np.linalg.eig(P1)
vp2, _ = np.linalg.eig(P2)
vp3, _ = np.linalg.eig(P3)

print("Multiplicité de 1 en valeur propre de P pour l'exemple 1 :", np.isclose(1, vp1).sum())
print("Multiplicité de 1 en valeur propre de P pour l'exemple 2 :", np.isclose(1, vp2).sum())
print("Multiplicité de 1 en valeur propre de P pour l'exemple 3 :", np.isclose(1, vp3).sum())


#-------------------Question 5-------------------#
print(" ")
print("-------------------Question 5-------------------")

alpha1 = 0.1
A_alpha11 = alpha1 * P1 + (1 - alpha1) / N
A_alpha12 = alpha1 * P2 + (1 - alpha1) / N
A_alpha13 = alpha1 * P3 + (1 - alpha1) / N

alpha2 = 0.5
A_alpha21 = alpha2 * P1 + (1 - alpha2) / N
A_alpha22 = alpha2 * P2 + (1 - alpha2) / N
A_alpha23 = alpha2 * P3 + (1 - alpha2) / N

vp1, _ = np.linalg.eig(A_alpha11)
vp2, _ = np.linalg.eig(A_alpha12)
vp3, _ = np.linalg.eig(A_alpha13)

print("Modules des valeurs propres de A de l'exemple 1 pour alpha = 0.1 :\n", np.array2string(np.sort(np.absolute(vp1))[::-1], precision = 2))
print("Modules des valeurs propres de A de l'exemple 2 pour alpha = 0.1 :\n", np.array2string(np.sort(np.absolute(vp2))[::-1], precision = 2))
print("Modules des valeurs propres de A de l'exemple 3 pour alpha = 0.1 :\n", np.array2string(np.sort(np.absolute(vp3))[::-1], precision = 2))
print("")

vp1, _ = np.linalg.eig(A_alpha21)
vp2, _ = np.linalg.eig(A_alpha22)
vp3, _ = np.linalg.eig(A_alpha23)

print("Modules des valeurs propres de A de l'exemple 1 pour alpha = 0.5 :\n", np.array2string(np.sort(np.absolute(vp1))[::-1], precision = 2))
print("Modules des valeurs propres de A de l'exemple 2 pour alpha = 0.5 :\n", np.array2string(np.sort(np.absolute(vp2))[::-1], precision = 2))
print("Modules des valeurs propres de A de l'exemple 3 pour alpha = 0.5 :\n", np.array2string(np.sort(np.absolute(vp3))[::-1], precision = 2))


# Partie algorithmique
#-------------------Question 6-------------------#
print(" ")
print("-------------------Question 6-------------------")

def puissance_iteree(A_alpha, tol):
    n = A_alpha.shape[0]
    r_1 = np.zeros(n)
    r_1[0] = 1  #avec un 1 et des 0, ||r||=1      
    r_0 = r_1 + tol #nous permet de rentrer dans la boucle
    iter = 0
    while np.linalg.norm(r_1 - r_0, ord=1) > tol :
        r_0 = r_1
        q_k = np.dot(A_alpha, r_1)
        r_1 = q_k / np.linalg.norm(q_k, ord=1)
        iter = iter + 1
    return [r_1, iter]

tol = 0.01
print("alpha = 0.5")

P1 = np.copy(Q1)
start = time.time()
P1[:, Nj1 == 0] += 1./N
A_alpha21 = alpha2 * P1 + (1 - alpha2) / N #on recalcule ces étapes pour que le temps obtenu soit comparable avec l'autre méthode
sortie = puissance_iteree(A_alpha11, tol)
end = time.time()
print("Exemple 1, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", end - start)

print("")


P2 = np.copy(Q2)
start = time.time()
P2[:, Nj2 == 0] += 1./N
A_alpha22 = alpha2 * P2 + (1 - alpha2) / N #on recalcule ces étapes pour que le temps obtenu soit comparable avec l'autre méthode
sortie = puissance_iteree(A_alpha22, tol)
end = time.time()
print("Exemple 2, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", end - start)


print("")

P3 = np.copy(Q3)
start = time.time()
P3[:, Nj3 == 0] += 1./N
A_alpha23 = alpha2 * P3 + (1 - alpha2) / N #on recalcule ces étapes pour que le temps obtenu soit comparable avec l'autre méthode
sortie = puissance_iteree(A_alpha23, tol)
end = time.time()
print("Exemple 3, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", end - start)

#-------------------Question 7-------------------#
print("")
print("-------------------Question 7-------------------")
print("cf code")


def puissance_iteree_adaptee(Q, alpha, tol):
    n = Q.shape[0]
    n_j = np.sum(Q, axis=0)
    colonnes_nulles = n_j == 0
    Q_sparse = csr_matrix(Q) #version creuse de Q
    r_1 = np.zeros(n)
    r_1[0] = 1          
    r_0 = r_1 + tol  
    nb_iterations = 0
    while np.linalg.norm(r_1 - r_0, ord=1) > tol :
        r_0 = r_1
        q_k = alpha * Q_sparse.dot(r_1) + (alpha * np.sum(r_1[colonnes_nulles]) + (1-alpha)*np.sum(r_1))/n
        r_1 = q_k / np.linalg.norm(q_k, ord=1)
        nb_iterations = nb_iterations + 1
    return [r_1, nb_iterations]



#-------------------Question 8-------------------#
print("")
print("-------------------Question 8-------------------")


print("avec l'utilisation de Q")
start = time.time()
sortie = puissance_iteree_adaptee(Q1, alpha2, tol)
end = time.time()
print("Exemple 1, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", time.time() - start)

print("")
start = time.time()
sortie = puissance_iteree_adaptee(Q2, alpha2, tol)
end = time.time()
print("Exemple 2, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", end - start)

print("")
start = time.time()
sortie = puissance_iteree_adaptee(Q3, alpha2, tol)
end = time.time()
print("Exemple 3, vecteur propre : \n", sortie[0])
print(sortie[1], "itérations")
print("Temps d'exécution :", end - start)
