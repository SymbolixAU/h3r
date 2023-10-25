# Test Traversal
expect_equal(
  gridDisk(
    cell = c("8cbe63562a54bff","85283473fffffff")
    , k = c(1L, 2L)
    )
  , list(c("8cbe63562a54bff", "8cbe63562a549ff", "8cbe63562a541ff", "8cbe63562a543ff", "8cbe63562a55dff", "8cbe63562a737ff", "8cbe63562a735ff"), c("85283473fffffff", "85283447fffffff", "8528347bfffffff", "85283463fffffff", "85283477fffffff", "8528340ffffffff", "8528340bfffffff", "85283457fffffff", "85283443fffffff", "8528344ffffffff", "852836b7fffffff", "8528346bfffffff", "8528346ffffffff", "85283467fffffff", "8528342bfffffff", "8528343bfffffff", "85283407fffffff", "85283403fffffff", "8528341bfffffff"))
  )

expect_error(
  gridDisk(
    cell = "a"
    , k = 1:2
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  gridDiskDistances(
    cell = c("85283473fffffff", "85283423fffffff")
    , k = c(1L, 0L)
    )
  , list(
    list(
      "cell" = c("85283473fffffff", "85283447fffffff", "8528347bfffffff", "85283463fffffff", "85283477fffffff", "8528340ffffffff", "8528340bfffffff")
      , "distance" = c(0, 1, 1, 1, 1, 1, 1))
    , list(
      "cell" = c("85283423fffffff")
      , "distance" = c(0))
    )
  )

expect_error(
  gridDiskDistances(
    cell = "a"
    , k = 1:2
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

# expect_equal(
#   gridRingUnsafe(
#     cell = c("85283473fffffff", "85283423fffffff")
#     , k = c(5L, 0L)
#     )
#   , list(c("85291a6ffffffff", "852834d3fffffff", "852834dbfffffff", "8529a937fffffff", "8529a923fffffff", "8529a92bfffffff", "85283693fffffff", "85283683fffffff", "8528368ffffffff", "85283617fffffff", "85283607fffffff", "85283633fffffff", "85283637fffffff", "852830cbfffffff", "852830cffffffff", "8528301bfffffff", "85283013fffffff", "8528308ffffffff", "85283087fffffff", "8528354bfffffff", "85283543fffffff", "85283553fffffff", "852835cbfffffff", "852835dbfffffff", "852834a7fffffff", "852834b7fffffff", "852834b3fffffff", "85283487fffffff", "85283483fffffff", "8528349bfffffff"), c("85283423fffffff"))
#   )
#
# expect_error(
#   gridRingUnsafe(
#     cell = c("a")
#     , k = 1:2
#   )
#   , pattern = "h3r - Error: Input vectors do not have consistent length"
# )

expect_equal(
  gridPathCells(
    origin = c("85283473fffffff","85283473fffffff")
    , destination = c("85283471fffffff","8528349ffffffff")
    )
  , list(c("85283473fffffff"), c("85283473fffffff", "8528340bfffffff", "85283403fffffff", "85283413fffffff", "8528348ffffffff", "85283483fffffff"))
  )

expect_error(
  gridPathCells(
    origin = c("a","b")
    , destination = c("b")
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  gridDistance(
    origin = c("85283473fffffff","85283473fffffff")
    , destination = c("8528342bfffffff","85283477fffffff")
    )
  , c(2L, 1L)
  )

expect_error(
  gridDistance(
    origin = c("a","b")
    , destination = c("b")
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  cellToLocalIj(
    origin = c("85283473fffffff","85283473fffffff")
    , cell = c("8528342bfffffff","85283477fffffff")
    )
  , list(
    "i" = c(25L, 26L)
    , "j" = c(13L, 14L)
    )
  )


expect_error(
  cellToLocalIj(
    origin = c("a","b")
    , cell = c("c")
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  localIjToCell(
    origin = c("85283473fffffff","85283473fffffff")
    , i = c(25L, 2L)
    , j = c(13L, 1L)
    )
  , c("8528342bfffffff", "852800c7fffffff")
  )

expect_error(
  localIjToCell(
    origin = c("a")
    , i = 1:2
    , j = 1:3
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)
