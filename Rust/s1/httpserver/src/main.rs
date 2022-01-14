mod server;
mod router;
mod handler;

use self::server::Server;

fn main() {
    let server = Server::new("localhost:3000");
    server.run();
}