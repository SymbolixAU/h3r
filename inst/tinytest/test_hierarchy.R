# Test Hierarchy
expect_equal(
  cellToParent(
    cell = c("8cbe63562a54bff","85283473fffffff")
    , parentRes = c(3L, 4L)
    )
  , c("83be63fffffffff", "8428347ffffffff")
  )

## Not an error: resoltions can be length 1
# expect_error(
#   cellToParent(cell = c("abc", "def"), parentRes = 1)
#   , pattern = "h3r - Error: Input vectors do not have consistent length"
# )

expect_error(
  cellToParent(cell = c("abc", "def"), parentRes = 1:3)
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  cellToChildren(
    cell = c("83be63fffffffff","85283473fffffff")
    , childRes = c(4L, 6L)
    )
  , list("83be63fffffffff" = c("84be631ffffffff", "84be633ffffffff", "84be635ffffffff", "84be637ffffffff", "84be639ffffffff", "84be63bffffffff", "84be63dffffffff"),"85283473fffffff" = c("862834707ffffff", "86283470fffffff", "862834717ffffff", "86283471fffffff", "862834727ffffff", "86283472fffffff", "862834737ffffff"))
  )

## No error: resolution can be length 1
# expect_error(
#   cellToChildren(
#     cell = c("a","b")
#     , childRes = 1
#   )
#   , pattern = "h3r - Error: Input vectors do not have consistent length"
# )

expect_error(
  cellToChildren(
    cell = c("a","b")
    , childRes = 1:3
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

res0 <- h3r::getRes0Cells()

## No error: resolutions can be length 1
# expect_error(
#   h3r::cellToChildren(
#     res0
#     , 1L
#     )
#   , pattern = "h3r - Error: Input vectors do not have consistent length"
# )

expect_error(
  h3r::cellToChildren(res0, rep(15, length(res0)))
)

expect_equal(
  cellToCenterChild(
    cell = c("83be63fffffffff","85283473fffffff")
    , childRes = c(4L, 7L)
    )
  , c("84be631ffffffff", "872834700ffffff")
  )

expect_error(
  cellToCenterChild(
    cell = c("a")
    , childRes = c(1, 2)
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  cellToChildPos(
    cell = c("8cbe63562a54bff","8cbe635631103ff")
    , parentRes = c(1L, 2L)
    )
  , c(1267125823, 137230626)
  )

expect_error(
  cellToChildPos(
    cell = "a"
    , parentRes = 1:2
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  childPosToCell(
    childPos = c(42, 41)
    , cell = c("85283473fffffff","85283473fffffff")
    , childRes = c(7L, 7L)
    )
  , c("872834730ffffff", "87283472effffff")
  )

expect_error(
  childPosToCell(
    childPos = c(1)
    , cell = c("a", "b")
    , childRes = c(1)
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  compactCells(
    gridDisk(
      cell = c("8cbe63562a54bff","85283473fffffff")
      , k = c(1L, 2L)
      )
    )
  , list(c("8cbe63562a54bff", "8cbe63562a549ff", "8cbe63562a541ff", "8cbe63562a543ff", "8cbe63562a55dff", "8cbe63562a737ff", "8cbe63562a735ff"), c("85283447fffffff", "8528340ffffffff", "8528340bfffffff", "85283457fffffff", "85283443fffffff", "8528344ffffffff", "852836b7fffffff", "8528342bfffffff", "8528343bfffffff", "85283407fffffff", "85283403fffffff", "8528341bfffffff", "8428347ffffffff"))
  )

expect_equal(
  uncompactCells(
    compactCells(
      gridDisk(
        cell = c("85283477fffffff","85283423fffffff")
        , k = c(1L, 2L)
        )
      )
    , res = c(5L, 5L)
    )
  , list(c("85283477fffffff", "85283473fffffff", "85283463fffffff", "85283467fffffff", "8528342bfffffff", "8528343bfffffff", "8528340ffffffff"), c("85283407fffffff", "8528340ffffffff", "85283477fffffff", "85283467fffffff", "85283093fffffff", "85283097fffffff", "8528355bfffffff", "85283553fffffff", "852835cbfffffff", "852835dbfffffff", "852834affffffff", "852834abfffffff", "85283423fffffff", "85283427fffffff", "8528342bfffffff", "8528342ffffffff", "85283433fffffff", "85283437fffffff", "8528343bfffffff"))
  )
