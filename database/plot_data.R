library(tidyverse)

con <- DBI::dbConnect(RSQLite::SQLite(), dbname = "Output/weather.db")

weather_db <- tbl(con, 'weather')

weatherDT <- weather_db %>% 
    select(everything()) %>%
    collect() %>%
    mutate(dateTime = as.POSIXct(dateTime, origin = '1970-01-01'))

weatherDT %>%
    # filter(channelName == 'temperature') %>%
    ggplot(aes(x = dateTime, y = value, color = assetId)) +
    geom_line() +
    gguptake::theme_uptake() +
    facet_wrap(~channelName)
