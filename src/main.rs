// use prompted::input;

use moose::routes;
use actix_web::{App, HttpServer};

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .configure(routes::config)
    })

    .bind("127.0.0.1:6969")?
    .run()
    .await
}