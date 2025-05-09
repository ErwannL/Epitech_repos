FROM maven:3.8.4-jdk-11-slim AS builder
COPY . /src/
WORKDIR /src/
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:11-jre-slim
CMD java -jar worker-jar-with-dependencies.jar
