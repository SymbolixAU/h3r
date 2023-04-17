if (requireNamespace("tinytest", quietly=TRUE)) {

  ## Set a seed to make the test deterministic
  set.seed(42)
  Sys.setenv("R_TESTS"="")
  tinytest::test_package("h3r")
}
