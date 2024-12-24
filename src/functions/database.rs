use rusqlite::{Connection, Result};

pub fn accounts_db() -> Result<()> {
    struct Database {
        conn: Connection,
    };

    impl Database {
        // Intializes the database
        fn init() -> Result<Self> {
            let conn = Connection::open("accounts.db")?;

            conn.execute(
                "CREATE TABLE IF NOT EXISTS checking (
                    id INTEGER PRIMARY KEY,
                    name TEXT,
                    balance FLOAT DEFAULT 0.00,
                    password TEXT,
                    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                    updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
                ",
                [],
            );

            Ok(Self {conn})
        }

        // Open a new account
        fn open(&self, variant: &str, name: &str, password: &str) -> Result<()> {
            self.conn.execute(
                format!("INSERT INTO {} (name, password) VALUES (?, ?)", variant),
                [name, password],
            );
        }

    }

    // Open the connection
}