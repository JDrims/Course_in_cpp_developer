CREATE TABLE "Сотрудник" (
    "ID" SERIAL PRIMARY KEY,
    "Имя" VARCHAR(255) NOT NULL,
    "Отдел" VARCHAR(100),
    "Начальник_id" INTEGER REFERENCES "Сотрудник"("ID") ON DELETE SET NULL
);

INSERT INTO "Сотрудник" ("Имя", "Отдел", "Начальник_id") 
VALUES ('Иван Иванов', 'Управление', NULL);

INSERT INTO "Сотрудник" ("Имя", "Отдел", "Начальник_id") 
VALUES ('Петр Петров', 'Продажи', 1);

SELECT * FROM "Сотрудник";