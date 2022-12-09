def uniform_good(a,b):
     return a + (b-a) * random.random() #je vous conseille d'implémenter celui du prof moi je l'ai fais a ma sauce


def Lplace(mu,b):
    test = random.random()
    return mu - b * sign(test - 0.5)* log(1-2 * absolute(test -0.5))


#Y is random uniform variable
def Xmmse(Y):
    return Y/3

#X is a random uniform variable
def Ymmse(X):
    return (2 - 3 * X + pow(X, 3)) / (3 * (1 -2 * X + pow(X, 2)))




def calcule():
    u = uniform_good(0,1)
    count = 400



def moyenne(valeurs):
  e=0
  a= len(valeurs) # la longueur de la liste
  for i in range(a):
      e = e + valeurs[i] # moyenne
  return e/a


y_tab = []

u = uniform_good(0,1)

for x in range(1000):
    mu = uniform_good(0,1)
    y_tab.append(Xmmse(pow(mu,1/3)))


print("moyenne xmmssee ", moyenne(y_tab))