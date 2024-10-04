use reqwest::blocking::Client;
use serde::{Deserialize, Serialize};
use std::error::Error;

#[derive(Debug, Serialize, Deserialize)]
struct Jwk {
    kid: String,
    kty: String,
    x5c: Vec<String>, // Certificate chain in x5c format
}

#[derive(Debug, Serialize, Deserialize)]
struct Jwks {
    keys: Vec<Jwk>,
}

fn do_fetch_jwks(url: &str) -> Result<Jwks, Box<dyn Error>> {
    let client = Client::new();
    let res = client.get(url).send()?;
    let jwks: Jwks = res.json()?;
    Ok(jwks)
}

fn fetch_jwks() {
    // Replace with your JWKS URL
    let jwks_url = "https://faasmattprov.eus2.attest.azure.net/certs";
    let jwks = do_fetch_jwks(jwks_url).unwrap();

    // Iterate over the keys and print out the x5c certificates
    for key in jwks.keys {
        println!("Key ID: {}", key.kid);
        println!("Key Alg: {}", key.kty);
        for (i, cert) in key.x5c.iter().enumerate() {
            println!("Certificate {}: \n{}", i + 1, cert);
        }
    }
}

fn main() {
    fetch_jwks();
}
