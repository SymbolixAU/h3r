library(tinytest)
library(reticulate)

h3 <- import("h3")
test_all(pkgdir = "./", testdir = "./tests/tinytest")
