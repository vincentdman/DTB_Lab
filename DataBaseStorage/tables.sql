CREATE TABLE timestamp_measurement(UNIX_TIME int, current_hour int, current_minute int, current_second int, current_day int, current_year year, PRIMARY KEY(UNIX_TIME));
CREATE TABLE node(NODE_ID int, location varchar, UNIX_TIME int, SAMPLE_NO int, PRIMARY KEY(NODE_ID, UNIX_TIME), FOREIGN KEY(UNIX_TIME) REFERENCES timestamp_measurement);
CREATE TABLE sample(SAMPLE_NO int, measured_variable varchar, value int, unit varchar, resolution int, NODE_ID int, PRIMARY KEY(SAMPLE_NO, measured_variable), FOREIGN KEY(SAMPLE_NO) REFERENCES node);
