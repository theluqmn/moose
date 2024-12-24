use actix_web::{get, web, App, HttpServer, HttpResponse, Responder};
use serde::Deserialize;

#[derive(Deserialize)]
struct AccountCreate {
    name: String,
    password: String,
}

#[get("/accounts/create")]
pub async fn accounts_create(query: web::Query<AccountCreate>) -> impl Responder {
    let name = query.name.as_deref();
    let password = query.password.as_deref();

    println!("{}", name);
    println!("{}", password);

    HttpResponse::Ok().body("Account created!")
}