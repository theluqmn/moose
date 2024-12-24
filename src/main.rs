// use prompted::input;

use actix_web::{get, web, App, HttpServer, Responder};

#[get("/")]
async fn index() -> impl Responder {
    println!("Route '/' called");
    "Hello, World!"
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new().service(index)
        .service(hello)
    })

    .bind("127.0.0.1:6969")?
    .run()
    .await
}