
# h3r

Interface to {h3lib}

R wrappers around Uber’s H3 library.

The wrappers are all vectorised, meaning each input can take a vector,
and / or return a vector.

e.g:

``` r
```

## Design Choices

- There is no `h3` class, or nice printing, or any fancy sugar-coating
  of what’s returned from the functions. I’ve kept the outputs as raw /
  primitive as possible
- All H3Indexes are returned as the String representation. If you want
  the `H3Index` / `uint64_t` type you need to use the C / C++ functions
  directly

## API

`inst/include/h3rapi.h`

## C API

### Example

An example package showing how to call the C API is in `/inst/capi`

## C++ API

An example package showing how to call the C++ API is in `/inst/cppapi`
