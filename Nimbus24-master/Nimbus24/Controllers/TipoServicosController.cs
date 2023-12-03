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
    public class TipoServicosController : Controller
    {
        private Nimbus24Context db = new Nimbus24Context();

        public ActionResult AddServico()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult AddServico([Bind(Include = "id,tipo,preco,id_Prestador,negociavel")] TipoServico tipoServico)
        {
            if (ModelState.IsValid)
            {
                tipoServico.negociavel = 0;

                var id = (from p in db.Prestador
                          where p.mail == User.Identity.Name
                          select p.Id);

                tipoServico.id_Prestador = id.ToList().ElementAt(0);

                db.TipoServico.Add(tipoServico);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.id_Prestador = new SelectList(db.Prestador, "Id", "nome", tipoServico.id_Prestador);
            return View(tipoServico);
        }


        // GET: TipoServicos
        public ActionResult Index()
        {
            var tipoServico = db.TipoServico.Include(t => t.Prestador);
            return View(tipoServico.ToList());
        }

        // GET: TipoServicos/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipoServico tipoServico = db.TipoServico.Find(id);
            if (tipoServico == null)
            {
                return HttpNotFound();
            }
            return View(tipoServico);
        }

        // GET: TipoServicos/Create
        public ActionResult Create()
        {
            ViewBag.id_Prestador = new SelectList(db.Prestador, "Id", "nome");
            return View();
        }

        // POST: TipoServicos/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "id,tipo,preco,id_Prestador,negociavel")] TipoServico tipoServico)
        {
            if (ModelState.IsValid)
            {
                db.TipoServico.Add(tipoServico);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.id_Prestador = new SelectList(db.Prestador, "Id", "nome", tipoServico.id_Prestador);
            return View(tipoServico);
        }

        // GET: TipoServicos/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipoServico tipoServico = db.TipoServico.Find(id);
            if (tipoServico == null)
            {
                return HttpNotFound();
            }
            ViewBag.id_Prestador = new SelectList(db.Prestador, "Id", "nome", tipoServico.id_Prestador);
            return View(tipoServico);
        }

        // POST: TipoServicos/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "id,tipo,preco,id_Prestador,negociavel")] TipoServico tipoServico)
        {
            if (ModelState.IsValid)
            {
                db.Entry(tipoServico).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.id_Prestador = new SelectList(db.Prestador, "Id", "nome", tipoServico.id_Prestador);
            return View(tipoServico);
        }

        // GET: TipoServicos/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipoServico tipoServico = db.TipoServico.Find(id);
            if (tipoServico == null)
            {
                return HttpNotFound();
            }
            return View(tipoServico);
        }

        // POST: TipoServicos/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            TipoServico tipoServico = db.TipoServico.Find(id);
            db.TipoServico.Remove(tipoServico);
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
