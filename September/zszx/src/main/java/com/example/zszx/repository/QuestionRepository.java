package com.example.zszx.repository;

import org.springframework.data.neo4j.annotation.Query;
import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

@Repository
public interface QuestionRepository extends Neo4jRepository<Long,Long> {
	@Query("match(n:Score)-[:from_time]->(m:Year) where n.province={pro} and m.year={yy} return n.mins")
	double[] getMinsOfYear_Province(@Param("yy") String yy, @Param("pro") String pro);

	@Query("match(n:Score)-[:from_time]->(m:Year) where n.province={pro} and n.subject={sub} and m.year={yy} return n.mins")
	double[] getMinsOfYear_Province_Subject(@Param("yy") String yy, @Param("pro") String pro,@Param("sub") String subject);

}
