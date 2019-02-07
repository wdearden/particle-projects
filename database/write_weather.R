library(curl)

URL <- "https://api.particle.io/v1/devices/3c0025000447373336323230/events?access_token=de0ed9a2be479d4c5cfd89abbf04bfc591a92c7b"

assets <- c(
    "3c0025000447373336323230" = 'downstairs'
    , "3c0027000447373336323230" = 'upstairs'
)

con <- curl(URL)
open(con)
readLines(con, n = 1)

dbConn <- DBI::dbConnect(RSQLite::SQLite(), dbname = "Output/weather.db")

while(isIncomplete(con)){
    out <- readLines(con, n = 3)
    channelName <- stringr::str_extract(out[2], '(?<=^event: ).*')
    data <- jsonlite::fromJSON(stringr::str_extract(out[3], '(?<=^data: ).*'))
    value <- as.numeric(data[['data']])
    dateTime <- anytime::anytime(data[['published_at']])
    assetId <- unname(assets[data[['coreid']]])
    DT <- tibble::tibble(
        dateTime = dateTime
        , assetId = assetId
        , channelName = channelName
        , value = value
    )
    print(DT)
    DBI::dbAppendTable(dbConn, "weather", DT)
    # cat(out, sep = "\n")
}
close(con)


