# Test Inspection

expect_equal(
  getResolution(cell = c("8cbe63562a54bff","85283473fffffff"))
  , c(12L, 5L)
  )

expect_equal(
  getBaseCellNumber(cell = c("8cbe63562a54bff","85283473fffffff"))
  , c(95L, 20L)
  )

expect_equal(
  isValidCell(cell = c("7ff7bfc91870","85283473fffffff"))
  , c(0L, 1L)
  )

expect_equal(
  isResClassIII(cell = c("8cbe63562a54bff","85283473fffffff"))
  , c(0L, 1L)
  )

expect_equal(
  isPentagon(cell = c("85080003fffffff","85283473fffffff"))
  , c(1L, 0L)
  )

expect_equal(
  getIcosahedronFaces(
    cell = c("85080003fffffff","85283473fffffff")
    )
  , list("85080003fffffff" = c(3L, 4L, 0L, 1L, 2L),"85283473fffffff" = c(7L))
  )
