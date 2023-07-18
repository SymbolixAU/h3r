# Test Directed Edges
expect_equal(
  areNeighborCells(
    origin = c("85283473fffffff","85283473fffffff")
    , destination = c("85283471fffffff","85283477fffffff")
    )
  , c(0, 1)
  )

expect_error(
  areNeighborCells(
    origin = c("85283473fffffff","85283473fffffff")
    , destination = c("85283471fffffff")
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  cellsToDirectedEdge(
    origin = c("85283471fffffff","85283473fffffff")
    , destination = c("85283475fffffff","85283477fffffff")
    )
  , c("115283471fffffff", "115283473fffffff")
  )

expect_error(
  cellsToDirectedEdge(
    origin = c("85283471fffffff","85283473fffffff")
    , destination = c("85283475fffffff")
  )
  , pattern = "h3r - Error: Input vectors do not have consistent length"
)

expect_equal(
  isValidDirectedEdge(
    edge = c("13d2a1672b34ffff","16a2a1072b59ffff")
    )
  , c(0, 1)
  )

expect_equal(
  getDirectedEdgeOrigin(
    edge = c("115283473fffffff","16a2a1072b59ffff")
    )
  , c("85283473fffffff", "8a2a1072b59ffff")
  )

expect_equal(
  getDirectedEdgeDestination(
    edge = c("115283473fffffff","16a2a1072b59ffff")
  )
  , c("85283477fffffff", "8a2a1072b597fff")
  )

expect_equal(
  directedEdgeToCells(
    edge = c("115283473fffffff","16a2a1072b59ffff")
    )
  , list(
    origin = c("85283473fffffff", "8a2a1072b59ffff")
    , destination = c("85283477fffffff", "8a2a1072b597fff")
    )
  )

expect_equal(
  originToDirectedEdges(
    origin = c("85283473fffffff","8cbe635631103ff")
    )
  , list(
    c("115283473fffffff", "125283473fffffff", "135283473fffffff", "145283473fffffff", "155283473fffffff", "165283473fffffff")
    , c("11cbe635631103ff", "12cbe635631103ff", "13cbe635631103ff", "14cbe635631103ff", "15cbe635631103ff", "16cbe635631103ff")
    )
  )

expect_equal(
  directedEdgeToBoundary(
    edge = c("115283473fffffff","115283477fffffff")
    )
  , list("115283473fffffff" = data.frame(
    "lat" = c(37.42012867767778, 37.33755608435298)
    , 'lng' = c(-122.03773496427027,-122.09042892904397)
    )
    , "115283477fffffff" = data.frame(
      "lat" = c(37.485965058551095, 37.4033911145053)
      , 'lng' = c(-122.21327339445754,-122.2658032483195)
    )
  )
)
