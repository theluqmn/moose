use actix_web::{get, web, HttpResponse, Responder};
use serde::Deserialize;

use crate::functions::accounts;

#[derive(Deserialize)]
struct AccountCreate {
    variant: String,
    name: String,
    password: String,
}

#[get("/accounts/create")]
pub async fn accounts_create(query: web::Query<AccountCreate>) -> impl Responder {
    let variant = &query.variant;
    let name = &query.name;
    let password = &query.password;

    // Input validation
    if variant.is_empty() {
        return HttpResponse::BadRequest().body("Variant cannot be empty")
    } else if !["checking", "savings"].contains(&variant.as_str()) {
        return HttpResponse::BadRequest().body("Invalid account variant")
    }

    if name.is_empty() {
        return HttpResponse::BadRequest().body("Name cannot be empty");
    } else if name.len() < 3 || name.len() > 20 {
        return HttpResponse::BadRequest().body("Name must be between 3 and 20 characters");
    } else if !name.chars().all(|c| c.is_alphanumeric() || c == '_') {
        return HttpResponse::BadRequest().body("Name can only contain alphanumeric characters and underscores");
    }

    if password.is_empty() {
        return HttpResponse::BadRequest().body("Password cannot be empty")
    } else if password.len() < 8 {
        return HttpResponse::BadRequest().body("Password must be at least 6 characters long");
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