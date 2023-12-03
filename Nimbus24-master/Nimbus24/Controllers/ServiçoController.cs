using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Nimbus24;

namespace Nimbus24.Controllers
{
    public class ServiçoController : Controller
    {
        private Nimbus24Context db = new Nimbus24Context();

        public ActionResult RegistarServico()
        {
            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail");
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua");
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome");
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult RegistarServico([Bind(Include = "id,preço,data,estado,idCliente,idPrestador,descrição,morada_id" )]Serviço serviço)
        {
            if (ModelState.IsValid)
            {

                var id = (from c in db.Cliente
                          where c.mail == User.Identity.Name
                          select c.id);

                serviço.estado = 0;

                serviço.idCliente = id.ToList().ElementAt(0);


                db.Serviço.Add(serviço);
                db.SaveChanges();
                return RedirectToAction("Index","Home");
            }


            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail", serviço.idCliente);
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua", serviço.morada_id);
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome", serviço.idPrestador);
            return View();
        }
        public ActionResult AddServico()
        {
            return View();
        }
        public ActionResult Contacts()
        {
            return View();
        }
        // GET: Serviço
        public ActionResult Index()
        {
            return View();
            
        }

        // GET: Serviço/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Serviço serviço = db.Serviço.Find(id);
            if (serviço == null)
            {
                return HttpNotFound();
            }
            return View(serviço);
        }

        // GET: Serviço/Create
        public ActionResult Create()
        {
            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail");
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua");
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome");
            return View();
        }

        // POST: Serviço/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "id,preço,data,estado,idCliente,idPrestador,descrição,morada_id")] Serviço serviço)
        {
            if (ModelState.IsValid)
            {
                db.Serviço.Add(serviço);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail", serviço.idCliente);
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua", serviço.morada_id);
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome", serviço.idPrestador);
            return View(serviço);
        }

        // GET: Serviço/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Serviço serviço = db.Serviço.Find(id);
            if (serviço == null)
            {
                return HttpNotFound();
            }
            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail", serviço.idCliente);
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua", serviço.morada_id);
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome", serviço.idPrestador);
            return View(serviço);
        }

        // POST: Serviço/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "id,preço,data,estado,idCliente,idPrestador,descrição,morada_id")] Serviço serviço)
        {
            if (ModelState.IsValid)
            {
                db.Entry(serviço).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.idCliente = new SelectList(db.Cliente, "id", "mail", serviço.idCliente);
            ViewBag.morada_id = new SelectList(db.Morada, "id", "rua", serviço.morada_id);
            ViewBag.idPrestador = new SelectList(db.Prestador, "Id", "nome", serviço.idPrestador);
            return View(serviço);
        }

        // GET: Serviço/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Serviço serviço = db.Serviço.Find(id);
            if (serviço == null)
            {
                return HttpNotFound();
            }
            return View(serviço);
        }

        // POST: Serviço/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Serviço serviço = db.Serviço.Find(id);
            db.Serviço.Remove(serviço);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
