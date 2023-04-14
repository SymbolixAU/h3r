# h3r
R-interface to {h3lib}

The wrappers are all vectorised, meaning each input can take a vector, and / or return a vector. 

e.g:

```r
> cellsToDirectedEdge(origin = c("85283471fffffff","85283473fffffff"), destination = c("85283475fffffff","85283477fffffff"))
[1] "115283471fffffff" "115283473fffffff"
```

```r
> cellToLatLng(cell = c("8cbe63562a54bff","8cbe635631103ff"))
$lat
[1] -37.82023 -37.81844

$lng
[1] 144.9832 144.9674
```

```r
> cellToLatLng("8cbe63562a54bff")
$lat
[1] -37.82023

$lng
[1] 144.9832
```

```r
> gridDisk(cell = c("8cbe63562a54bff","8cbe635631103ff"), k = c(1L, 2L))
[[1]]
[1] "8cbe63562a54bff" "8cbe63562a549ff" "8cbe63562a541ff" "8cbe63562a543ff" "8cbe63562a55dff" "8cbe63562a737ff" "8cbe63562a735ff"

[[2]]
 [1] "8cbe635631103ff" "8cbe635631101ff" "8cbe635631107ff" "8cbe635631139ff" "8cbe635631115ff" "8cbe63563111dff" "8cbe63563110bff" "8cbe635631109ff" "8cbe63563110dff" "8cbe635631105ff" "8cbe63563112bff" "8cbe63563113dff"
[13] "8cbe635631131ff" "8cbe63563113bff" "8cbe635631117ff" "8cbe635631111ff" "8cbe635631119ff" "8cbe635631157ff" "8cbe635631155ff"
```

## Design Choices
- There is no `h3` class, or nice printing, or any fancy sugar-coating of what's returned from the functions. I've kept the outputs as raw / primitive as possible
- All H3Indexes are returned as the String representation. If you want the `H3Index` / `uint64_t` type you need to use the C / C++ functions directly
