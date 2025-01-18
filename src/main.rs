// use prompted::input;

mod routes;
mod functions;
use actix_web::{App, HttpServer};

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    println!("Moose\nhttps://github.com/theluqmn/moose\n----");
    HttpServer::new(|| {
        App::new()
            .configure(routes::config)
    })

    .bind("127.0.0.1:6969")?
    .run()
    .await
}