

## Read `h3libapi.h` and write all 'inline' function defs to `init.c`

lines <- readLines("~/Documents/github/h3lib/inst/include/h3libapi.h")
fns <- lines[ grepl("inline ", lines) ]
fns <- gsub("inline ", "", fns)
fns <- gsub("\\(.*","",fns)
fns <- gsub(" ", " (*", fns)
fns <- paste0(fns, ");\n")
cat(fns)
