use rusqlite::{Connection, Result};
use uuid::Uuid;

pub struct Accounts {
    conn: Connection,
}

impl Accounts {
    // Initializes the database
    pub fn init() -> Result<Self> {
        let conn = Connection::open("database/accounts.db")?;

        conn.execute(
            "CREATE TABLE IF NOT EXISTS checking (
                id TEXT PRIMARY KEY,
                name TEXT,
                balance FLOAT DEFAULT 0.00,
                password TEXT,
                created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
            )",
            [],
        )?;

        Ok(Self { conn })
    }

    // Check if account exists

    // Verify password

    // Open a new account
    pub fn open(&self, variant: &str, name: &str, password: &str) -> Result<()> {
        let id = Uuid::new_v4().to_string();
        self.conn.execute(
            &format!("INSERT INTO {} (id, name, password) VALUES (?, ?, ?)", variant),
            [id, name.to_string(), password.to_string()],
        )?;
        Ok(())
    }

    // Update account details

    // Delete account
}