pub mod accounts;

use actix_web::web;

pub fn config(cfg: &mut web::ServiceConfig) {
    cfg.service(accounts::accounts_create);
}