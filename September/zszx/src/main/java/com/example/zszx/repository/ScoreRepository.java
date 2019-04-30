package com.example.zszx.repository;

import com.example.zszx.node.Score;
import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface ScoreRepository extends Neo4jRepository<Score,Long> {
    List<Score> findByProvince(String province);    //根据省份找分数
    List<Score> findBySubject(String subject);
}
