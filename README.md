# Rust JWT Validation

This library validates the signature of a JWT against a set of hard-coded
certificates.

The library is written in pure Rust, and is meant to be cross-compiled to
WebAssembly, and called through its C++ binding.

We use the library in the context of TLess, where we need to validate the JWT
sent by the Azure Attestation Service inside a WebAssembly function inside an
SGX enclave.

To build the library do:

```bash
cd jwt-verify
cargo build --target wasm32-wasip1 --release
```

To update the hard-coded certificates just run:

```bash
cd fetch-jwks
cargo run
```

and copy the certificates into the rust library.
