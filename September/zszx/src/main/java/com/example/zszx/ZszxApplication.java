package com.example.zszx;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.domain.EntityScan;
import org.springframework.data.neo4j.repository.config.EnableNeo4jRepositories;


@EnableNeo4jRepositories(basePackages = "com.example.zszx.repository")
@EntityScan(basePackages ="com.example.zszx.node")
@SpringBootApplication
public class ZszxApplication {

    public static void main(String[] args) {
        SpringApplication.run(ZszxApplication.class, args);
    }
}
