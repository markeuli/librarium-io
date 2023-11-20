// Sidebar links functionality
const sideLinks = document.querySelectorAll('.sidebar .side-menu li a:not(.logout)');
sideLinks.forEach(item => {
    item.addEventListener('click', () => {
        sideLinks.forEach(link => {
            link.parentElement.classList.remove('active');
        });
        item.parentElement.classList.add('active');
    });
});

// Toggle sidebar visibility
const menuBar = document.querySelector('.content nav .bx.bx-menu');
const sideBar = document.querySelector('.sidebar');
menuBar.addEventListener('click', () => {
    sideBar.classList.toggle('close');
});

// Search button functionality
const searchBtn = document.querySelector('.content nav form .form-input button');
const searchBtnIcon = document.querySelector('.content nav form .form-input button .bx');
const searchForm = document.querySelector('.content nav form');

searchBtn.addEventListener('click', function (e) {
    if (window.innerWidth < 576) {
        e.preventDefault();
        searchForm.classList.toggle('show');
        searchBtnIcon.classList.toggle('bx-search');
        searchBtnIcon.classList.toggle('bx-x');
    }
});

// Responsive adjustments
function adjustSidebar() {
    if (window.innerWidth < 768) {
        sideBar.classList.add('close');
    } else {
        sideBar.classList.remove('close');
    }
    if (window.innerWidth > 576) {
        searchBtnIcon.classList.replace('bx-x', 'bx-search');
        searchForm.classList.remove('show');
    }
}

window.addEventListener('resize', adjustSidebar);

// Tab functionality
const tabLinks = document.querySelectorAll('.tabs .side-menu li');
tabLinks.forEach(link => {
    link.addEventListener('click', () => {
        document.querySelector('.tabs .active').classList.remove('active');
        link.classList.add('active');
    });
});



document.addEventListener('DOMContentLoaded', function () {
    const addLibrarianBtn = document.querySelector('.add-item button'); // Corrected class name
    const modal = document.getElementById('additemModal');
    const closeBtn = document.querySelector('.modal .close');
    const form = document.getElementById('addBookForm');
    const tableofcontent = document.getElementById('itemTable'); // Corrected ID

    addLibrarianBtn.addEventListener('click', () => { // Corrected variable name
        modal.style.display = 'block';
        form.reset(); // Reset the form when opening the modal
    });

    closeBtn.addEventListener('click', () => {
        modal.style.display = 'none';
    });

    window.addEventListener('click', (event) => {
        if (event.target === modal) {
            modal.style.display = 'none';
        }
    });

    form.addEventListener('submit', (event) => {
        event.preventDefault();

        const id = form.elements.id.value;
        const name = form.elements.name.value;
        const dob = form.elements.author.value; // Changed to dob
        const email = form.elements.category.value; // Changed to email

        const newRow = document.createElement('tr');
        newRow.innerHTML = `
          <td>${id}</td>
          <td>${name}</td>
          <td>${dob}</td>
          <td>${email}</td>
          <td><button class="delete-button"><i class="bx bxs-trash"></i></button></td>
        `;

        tableofcontent.appendChild(newRow);

        form.reset(); // Reset the form after submission
        modal.style.display = 'none';
    });

    tableofcontent.addEventListener('click', (event) => {
        const target = event.target;
        if (target.classList.contains('delete-button') || target.parentElement.classList.contains('delete-button')) {
            deleteItem(target);
        }
    });

    function deleteItem(button) {
        const row = button.closest('tr'); // Find the closest table row
        if (row) {
            row.remove(); // Remove the row
        }
    }
});
