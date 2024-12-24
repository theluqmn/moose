use actix_web::{get, web, App, HttpServer, Responder};

#[get("/accounts/create")]
pub async fn accounts_create() -> impl Responder {
    "Creating an account..."
}