CREATE table IF NOT EXISTS Ganres (
    UniqueID SERIAL PRIMARY KEY,
    ID_ganre VARCHAR(50) UNIQUE NOT NULL,
    Title_ganre VARCHAR(100) NOT NULL
);

CREATE table IF NOT EXISTS Performers (
    ID_performer SERIAL PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Ganres INTEGER REFERENCES Ganres(UniqueID)
);

CREATE table IF NOT EXISTS Albums (
    ID_album SERIAL PRIMARY KEY,
    Title_album VARCHAR(255) NOT NULL,
    Year_of_release INTEGER CHECK (Year_of_release > 1999),
    Performers INTEGER REFERENCES Performers(ID_performer)
);

CREATE table IF NOT EXISTS Tracks (
    ID_track SERIAL PRIMARY KEY,
    Title_track VARCHAR(255) NOT NULL,
    Duration INTEGER,
    Album INTEGER REFERENCES Albums(ID_album)
);