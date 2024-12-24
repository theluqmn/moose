use actix_web::{get, web, App, HttpServer, HttpResponse, Responder};
use serde::Deserialize;

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

    HttpResponse::Ok().body("Account created!")
}