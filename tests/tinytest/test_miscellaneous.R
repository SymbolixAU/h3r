# Test Miscellaneous
expect_equal(degsToRads(c(45, 50)), c(0.7853981633974483, 0.8726646259971648))
expect_equal(radsToDegs( c(0.7853981633974483, 0.8726646259971648)), c(45, 50))
expect_equal(getHexagonAreaAvgKm2(c(5L, 6L)), c(252.9038581819449, 36.12906216441245))
expect_equal(getHexagonAreaAvgM2(c(5L, 6L)), c(252903858.1819452, 36129062.1644125))

expect_equal(getHexagonAreaAvgKm2(c(5L, 6L)), c(h3$get_hexagon_area_avg(5, unit='km^2'), h3$get_hexagon_area_avg(6, unit='km^2')))

h3$unstable$v4$grid_disk

