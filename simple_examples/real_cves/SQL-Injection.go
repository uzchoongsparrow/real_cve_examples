package main

import (
    "database/sql"
    "fmt"
    _ "github.com/go-sql-driver/mysql"
)

func main() {
    db, err := sql.Open("mysql", "user:password@/dbname")
    if err != nil {
        panic(err.Error())
    }
    defer db.Close()

    var userInput string
    fmt.Println("Enter username:")
    fmt.Scanln(&userInput)

    var userID string
    query := fmt.Sprintf("SELECT id FROM users WHERE username = '%s'", userInput) // SQL Injection 취약점
    err = db.QueryRow(query).Scan(&userID)
    if err != nil {
        panic(err.Error())
    }
    fmt.Println("User ID:", userID)
}
