package com.example.zszx.controller;

import com.example.zszx.service.QuestionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Servlet implementation class Talk
 */
@Controller
@WebServlet("/njnu_zs")
//@RequestMapping("/njnu_zs")
public class Talk extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Autowired
	QuestionService questService;

	/**
     * Default constructor. 
     */
    public Talk() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	@RequestMapping("/njnu_zs")
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("UTF-8");
	    PrintWriter out = response.getWriter();
	    String first = request.getParameter("a");//
	    //String second = request.getParameter("second");//
		String result="";
		try {
			result = questService.answer(first);
		}
		catch (Exception e){
			result="不好意思，超出我的现有知识了呢！";;
		}
	    System.out.println(first); // 
		out.println(result); //

		//response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
