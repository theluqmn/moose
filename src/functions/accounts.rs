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

        conn.execute(
            "CREATE TABLE IF NOT EXISTS savings (
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
    // pub fn exists(&self, variant: &str, id: &str) -> Result<bool> {
    //     // SQL operation
    //     let mut stmt = self.conn.prepare(&format!("SELECT COUNT(*) FROM {} WHERE id = {}", variant, id))?;
    //     let count: i32 = stmt.query_row([id], |row| row.get(0))?;

    //     Ok(count > 0)
    // }

    // Verify password

    // Open a new account
    pub fn open(&self, variant: &str, name: &str, password: &str) -> Result<String> {
        let id = Uuid::new_v4().to_string();

        self.conn.execute(
            &format!("INSERT INTO {} (id, name, password) VALUES (?, ?, ?)", variant),
            [id.clone(), name.to_string(), password.to_string()],
        )?;

        Ok(id)
    }

    // Update account details

    // Delete account
}