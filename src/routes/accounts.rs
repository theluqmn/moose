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
    let name = &query.name;
    let password = &query.password;

    // Input validation
    if name.is_empty() || password.is_empty() {
        return HttpResponse::BadRequest().body("Name and password cannot be empty");
    }

    if name.len() < 3 || name.len() > 20 {
        return HttpResponse::BadRequest().body("Name must be between 3 and 20 characters");
    }

    if password.len() < 8 {
        return HttpResponse::BadRequest().body("Password must be at least 6 characters long");
    }

    if !name.chars().all(|c| c.is_alphanumeric() || c == '_') {
        return HttpResponse::BadRequest().body("Name can only contain alphanumeric characters and underscores");
    }

    // Create a new database instance
    let db = accounts::Accounts::init().unwrap();
    let id = match db.open("checking", name, password) {
        Ok(id) => id,
        Err(e) => return HttpResponse::InternalServerError().body(format!("Failed to create account: {}", e))
    };

    println!("Created new account with ID: {}, name: {}", id, name);    
    HttpResponse::Ok().body("Account created!")
}