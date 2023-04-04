# Test Vertexes
expect_equal(cellToVertex(cell = c("8cbe63562a54bff","85283473fffffff"), vertexNum = c(3L, 2L)), c("25cbe63562a543ff", "205283463fffffff"))
expect_equal(cellToVertexes(cell = c("8cbe63562a54bff","85283473fffffff")), list("8cbe63562a54bff" = c("24cbe63562a549ff","25cbe63562a541ff","24cbe63562a541ff","25cbe63562a543ff","24cbe63562a54bff","25cbe63562a54bff"), "85283473fffffff" = c("22528340bfffffff","235283447fffffff","205283463fffffff","255283463fffffff","22528340ffffffff","23528340bfffffff")))
expect_equal(vertexToLatLng(vertex = c("24cbe63562a549ff","255283463fffffff")), list("lat" = c(-37.82029703468319, 37.42012867767778), "lng" = c(144.9833025854974, -122.03773496427027)))
expect_equal(isValidVertex(vertex = c("255283463fffffff","2553463463463fffffff")), c(1, 0))
