sourceCpp('practica1.cpp')
# X contains the inputs as a matriX of real numbers
data("iris")
# X contains the input attributes (eXcluding the class)
X <- iris[,-5]
# y contains the response variable (named medv, a numeric value)
y <- iris[,5]

# From dataframe to matriX
X <- as.matrix(X)
# From factor to integer
y <- as.integer(y)

# This is the point we want to predict

X0 <- c(5.80, 3.00, 4.35, 1.30)

# Using my_knn and FNN:knn to predict point X0
# Using the same number of neighbors, it should be similar (k=1)
my_knn_C(X, X0, y)
library(FNN)
FNN::knn(X, matrix(X0, nrow = 1), y, k=1)
