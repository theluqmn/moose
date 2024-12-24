use actix_web::{get, web, HttpResponse, Responder};
use serde::Deserialize;

use crate::functions::accounts;

#[derive(Deserialize)]
struct AccountCreate {
    name: String,
    password: String,
}

#[get("/accounts/create")]
pub async fn accounts_create(query: web::Query<AccountCreate>) -> impl Responder {
    let name = &query.name; // Directly reference the name
    let password = &query.password; // Directly reference the password

    println!("Name: {}", name);
    println!("Password: {}", password);

    // Create a new database instance
    let db = accounts::Accounts::init().unwrap();
    db.open("checking", name, password).unwrap();

    HttpResponse::Ok().body("Account created!")
}